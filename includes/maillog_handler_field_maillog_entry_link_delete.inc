<?php

/**
 * @file
 * Handler for providing a 'Delete link' in views.
 */

/**
 * Handler for providing a 'Delete link' in views.
 */
class MaillogHandlerFieldMaillogEntryLinkDelete extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function construct() {
    parent::construct();
    $this->additional_fields['maillog_id'] = 'maillog_id';
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    // Ensure user has access to edit this node.
    if (!user_access('delete maillog')) {
      return;
    }
    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    return l($text, "maillog/delete/$values->maillog_id", array('query' => drupal_get_destination()));
  }

}
