<?php

/**
 * @file
 * Provides drupal_mail_wrapper function
 */

/**
 * Implementation of drupal_mail_wrapper().
 */
function drupal_mail_wrapper($message) {
  // Static variable used to check for recursive mail sending and prevent it
  static $recursive_send;

  if ($recursive_send) {
    drupal_set_message(t('Mail Log has detected recursive mail sending.'), 'warning');
    return;
  }

  $recursive_send = TRUE;

  // Log the e-mail
  if (variable_get('maillog_log', TRUE)) {
    $record = new stdClass;

    $record->header_message_id = isset($message['headers']['Message-ID']) ? $message['headers']['Message-ID'] : NULL;
    $record->subject = $message['subject'];
    $record->body = $message['body'];
    $record->header_from = $message['from'];
    $record->header_to = $message['to'];
    $record->header_reply_to = isset($message['headers']['Reply-To']) ? $message['headers']['Reply-To'] : '';
    $record->header_all = serialize($message['headers']);
    $record->sent_date = time();

    drupal_write_record('maillog', $record);
  }

  // Display the e-mail using Devel module
  if (variable_get('maillog_devel', TRUE) && function_exists('dpm')) {
    $devel_message_array = array();
    $devel_message_array[t('Subject')] = $message['subject'];
    $devel_message_array[t('From')] = $message['from'];
    $devel_message_array[t('To')] = $message['to'];
    $devel_message_array[t('Reply-To')] = $message['reply_to'];
    $devel_message_array[t('Header')] = $message['headers'];
    $devel_message_array[t('Body')] = $message['body'];

    dpm($devel_message_array, 'maillog');
  }

  // Send the e-mail
  if (variable_get('maillog_send', TRUE)) {
    $mimeheaders = array();
    foreach ($message['headers'] as $name => $value) {
      $mimeheaders[] = $name .': '. mime_header_encode($value);
    }
    $ret = mail(
      $message['to'],
      mime_header_encode($message['subject']),
      str_replace("\r", '', $message['body']),
      join("\n", $mimeheaders)
    );
  }
  else {
    if (user_access('administer maillog')) {
      drupal_set_message(t('Sending of e-mail messages is disabled by Mail Log module. Go ' . l('here', 'admin/settings/maillog') . ' to enable.'), 'warning', TRUE);
    }
    else {
      drupal_set_message(t('Sending of e-mail messages is disabled by Mail Log module. Please contact your administrator.'), 'warning', TRUE);
    }
    $ret = TRUE;
  }
  $recursive_send = FALSE;
  return $ret;
}
