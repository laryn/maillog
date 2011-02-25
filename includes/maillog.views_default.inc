<?php

/**
 * @file
 * Creates the default view for the 'Log Mail' module
 */

/**
 * Implementation of hook_views_default_views().
 */
function maillog_views_default_views() {
$view = new view;
$view->name = 'maillog';
$view->description = 'Displays the list of e-mails logged by the \'Mail Log\' module.';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'maillog';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'maillog_id' => array(
    'label' => 'Maillog_ID',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'exclude' => 1,
    'id' => 'maillog_id',
    'table' => 'maillog',
    'field' => 'maillog_id',
    'relationship' => 'none',
  ),
  'sent_date' => array(
    'label' => 'Date',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'exclude' => 0,
    'id' => 'sent_date',
    'table' => 'maillog',
    'field' => 'sent_date',
    'relationship' => 'none',
  ),
  'header_message_id' => array(
    'id' => 'header_message_id',
    'table' => 'maillog',
    'field' => 'header_message_id',
  ),
  'subject' => array(
    'label' => 'Subject',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 1,
      'path' => 'maillog/details/[maillog_id]',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'exclude' => 0,
    'id' => 'subject',
    'table' => 'maillog',
    'field' => 'subject',
    'relationship' => 'none',
  ),
  'header_from' => array(
    'label' => 'From',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'exclude' => 0,
    'id' => 'header_from',
    'table' => 'maillog',
    'field' => 'header_from',
    'relationship' => 'none',
  ),
  'header_to' => array(
    'label' => 'To',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'exclude' => 0,
    'id' => 'header_to',
    'table' => 'maillog',
    'field' => 'header_to',
    'relationship' => 'none',
  ),
  'delete_maillog_entry' => array(
    'label' => 'Delete link',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'exclude' => 0,
    'id' => 'delete_maillog_entry',
    'table' => 'maillog',
    'field' => 'delete_maillog_entry',
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'sent_date' => array(
    'order' => 'DESC',
    'id' => 'sent_date',
    'table' => 'maillog',
    'field' => 'sent_date',
    'relationship' => 'none',
  ),
));
$handler->override_option('access', array(
  'type' => 'perm',
  'perm' => 'view maillog',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('use_pager', '1');
$handler->override_option('style_plugin', 'table');
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->override_option('path', 'maillog/log');
$handler->override_option('menu', array(
  'type' => 'normal',
  'title' => 'maillog',
  'description' => 'Show the logged eMails',
  'weight' => '0',
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));

  $views[$view->name] = $view;
  return $views;
}
