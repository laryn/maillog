<?php

/**
 * @file
 * Menu API callback handlers for Maillog pages.
 */

/**
 * Display a maillog record.
 *
 * @param array $maillog
 *   A maillog record that is to be deleted with an 'idmaillog' value.
 *
 * @return string
 */
function maillog_maillog_page($maillog) {
  return theme('maillog', array('maillog' => $maillog));
}

/**
 * Delete a maillog record.
 *
 * @param array $maillog
 *   A maillog record that is to be deleted with an 'idmaillog' value.
 */
function maillog_maillog_delete($maillog) {
  $idmaillog = $maillog['idmaillog'];
  $result = db_query("DELETE FROM {maillog} WHERE idmaillog = :id", array(':id' => $idmaillog));
  if ($result == FALSE) {
    drupal_set_message(t('A Problem occured when deleting Mail with ID !idmaillog !', array('!idmaillog' => $idmaillog)));
  }
  else {
    drupal_set_message(t('Mail with ID !idmaillog has been deleted!', array('!idmaillog' => $idmaillog)));
  }
  drupal_goto('admin/reports/maillog');
}
