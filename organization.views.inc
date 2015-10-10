<?php
/**
 * @file
 * Views integration for the Organization module.
 */

/**
 * Implements hook_views_data_alter().
 */
function organization_views_data_alter(&$data) {
  if (!isset($data['users']['type'])) {
    $data['users']['bundle'] = array(
      'title' => t('Bundle'),
      'help' => t('The user bundle (for example, "user" or "organization").'),
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
  }
}
