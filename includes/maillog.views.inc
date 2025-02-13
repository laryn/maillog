<?php

/**
 * @file
 * Make the fields from node type 'Logged Mail' available in views.
 */

/**
 * Implements hook_views_data().
 */
function maillog_views_data() {
  $data['maillog']['table']['group'] = t('Maillog');

  $data['maillog']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Maillog'),
    'help' => t("This table contains the logged e-mails."),
    'weight' => -10,
  );

  $data['maillog']['id'] = array(
    'title' => t('Maillog ID'),
    'help' => t('The primary key of the maillog table.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['maillog']['header_message_id'] = array(
    'title' => t('Message_ID'),
    'help' => t("The 'Message_ID' e-mail address."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['maillog']['header_from'] = array(
    'title' => t('From'),
    'help' => t("The 'From' field of the e-mail address."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['maillog']['header_to'] = array(
    'title' => t('To'),
    'help' => t("The 'To' field of the e-mail address."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['maillog']['header_reply_to'] = array(
    'title' => t('Reply To'),
    'help' => t("The 'Reply-To' field of the e-mail address."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['maillog']['header_all'] = array(
    'title' => t('Header'),
    'help' => t("The 'Header' field of the e-mail."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['maillog']['body'] = array(
    'title' => t('Body'),
    'help' => t("The 'Body' field of the e-mail."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['maillog']['subject'] = array(
    'title' => t('Subject'),
    'help' => t("The 'Subject' field of the e-mail."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['maillog']['sent_date'] = array(
    'title' => t('Date'),
    'help' => t("The 'Date' field of the e-mail."),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['maillog']['delete_maillog'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete an email entry from the maillog table.'),
      'handler' => 'MaillogHandlerFieldMaillogLinkDelete',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_handlers().
 */
function maillog_views_handlers() {
  return array(
    'info' => array(
      'path' => backdrop_get_path('module', 'maillog') . '/includes',
    ),
    'handlers' => array(
      // Field handlers.
      'MaillogHandlerFieldMaillogLinkDelete' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
