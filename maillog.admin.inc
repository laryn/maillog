<?php

/**
 * @file
 * Settings functionality for the MailLog module.
 */

/**
 * Form API callback for the Maillog settings form.
 */
function maillog_admin_settings() {
  $form = array();
  $config = config('maillog.settings');
  $form = array();

  $form['#config'] = 'maillog.settings';
  $form['maillog_send'] = array(
    '#type' => 'checkbox',
    '#title' => t("Allow the e-mails to be sent."),
    '#default_value' => $config->get('maillog_send'),
  );

  $form['maillog_log'] = array(
    '#type' => 'checkbox',
    '#title' => t("Create table entries in maillog table for each e-mail."),
    '#default_value' => $config->get('maillog_log'),
  );

  $form['maillog_devel'] = array(
    '#type' => 'checkbox',
    '#title' => t("Display the e-mails on page using devel module (if enabled)."),
    '#default_value' => $config->get('maillog_devel'),
  );

  if (module_exists('mailsystem')) {
    $mailsystem_classes = mailsystem_get_classes();
    // Maillog will be unset, because it would cause an recursion.
    unset($mailsystem_classes['MaillogMailSystem']);
    $form['maillog_engine'] = array(
      '#type' => 'select',
      '#title' => t("Select the mail system which should be used."),
      '#default_value' => $config->get('maillog_engine'),
      '#options' => $mailsystem_classes,
    );
  }

  $form['maillog_body'] = array(
    '#type' => 'radios',
    '#title' => t("Mail body logging"),
    '#description' => t('Loging the body can fill your DB if you have a lot of big mails or disclose sensitive information which should not be stored in the DB.'),
    '#options' => array(
      'all' => t('Log entire body.'),
      'partial' => t('Log the first 512 characters.'),
      'none' => t('The mail body is not logged at all.'),
    ),
    '#default_value' => $config->get('maillog_body'),
  );

  $form['maillog_row_limit'] = array(
    '#type' => 'select',
    '#title' => t('Maillog messages to keep'),
    '#default_value' => $config->get('maillog_row_limit'),
    '#options' => array(0 => t('All')) + backdrop_map_assoc(array(100, 1000, 10000)),
    '#description' => t('The maximum number of messages to keep in the maillog. Requires cron.'),
  );

  $form['maillog_delete_time'] = array(
    '#type' => 'select',
    '#title' => 'Mailog log duration',
    '#description' => t("Set for how long Maillog should store reports."),
    '#options' => array(
      '0' => t('- Do not autodelete -'),
      '3600' => t('1 hr'),
      '7200' => t('2 hrs'),
      '21600' => t('6 hrs'),
      '43200' => t('12 hrs'),
      '86400' => t('24 hrs'),
      '172800' => t('2 days'),
      '259200' => t('3 days'),
      '604800' => t('7 days'),
      '1209600' => t('14 days'),
      '2419200' => t('28 days'),
    ),
    '#default_value' => $config->get('maillog_delete_time'),
  );

  return system_settings_form($form);
}
