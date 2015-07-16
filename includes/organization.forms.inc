<?php
/**
 * @file
 * Forms for the Organization module.
 */

/**
 * Form builder for creating or updating an organization.
 */
function organization_form($form, &$form_state, $org = NULL, $owner = NULL) {
  form_load_include($form_state, 'inc', 'organization', 'includes/organization.forms');

  if ($org === NULL) {
    $org = entity_create('user', array(
      'bundle' => 'organization',
    ));
    $organization_wrapper = entity_metadata_wrapper('user', $org);
    $organization_wrapper->organization_owner = $owner ?: $GLOBALS['user'];
  }

  $form_state['organization'] = $org;

  field_attach_form('user', $org, $form, $form_state);

  return $form;
}

/**
 * Validate callback.
 *
 * @see organization_form()
 */
function organization_form_validate(&$form, &$form_state) {
  field_attach_form_validate('user', $form_state['organization'], $form, $form_state);
}

/**
 * Submit callback.
 *
 * @see organization_form()
 */
function organization_form_submit(&$form, &$form_state) {
  $org = $form_state['organization'];

  field_attach_submit('user', $org, $form, $form_state);
  user_save($org);

  $form_state['redirect'] = 'organization/' . $org->uid;
}
