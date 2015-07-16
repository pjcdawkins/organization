<?php
/**
 * @file
 * Features integration for the Organization module.
 */

/**
 * Implements hook_field_default_field_bases().
 *
 * This hook is provided by the Features module (not the Field module).
 */
function organization_field_default_field_bases() {
  // Let the Features module know about this module's field bases.
  $field_bases = array();
  module_load_include('inc', 'organization', 'includes/organization.fields');
  foreach (organization_required_field_bases() as $field_name => $field) {
    if (!isset($field_bases[$field_name])) {
      $field_bases[$field_name] = $field;
    }
  }

  return $field_bases;
}
