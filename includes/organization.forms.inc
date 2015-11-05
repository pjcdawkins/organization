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

  $title = $org
    ? t('Update organization @name', array('@name' => $org->name))
    : t('Create new organization');
  drupal_set_title($title, PASS_THROUGH);

  if (!is_object($org)) {
    $org = entity_create('user', array(
      'uid' => null,
      'bundle' => 'organization',
      'status' => 1,
    ));
    $org_wrapper = entity_metadata_wrapper('user', $org);
    $org_wrapper->organization_owner = $owner ?: $GLOBALS['user'];
  }
  elseif ($org->bundle != 'organization') {
    throw new \InvalidArgumentException('Incorrect organization bundle');
  }
  else {
    $org_wrapper = entity_metadata_wrapper('user', $org);
  }

  $form['#user'] = $org;
  $form_state['user'] = $org;

  user_account_form($form, $form_state);

  field_attach_form('user', $org, $form, $form_state);

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  if (isset($_GET['destination'])) {
    $cancel_path = $_GET['destination'];
  }
  elseif (!empty($org->uid)) {
    $cancel_path = 'user/' . $org->uid;
  }
  elseif ($owner_uid = $org_wrapper->organization_owner->uid->value()) {
    $cancel_path = 'user/' . $owner_uid . '/organizations';
  }
  if (isset($cancel_path)) {
    $form['actions']['cancel_link'] = array(
      '#markup' => l(t('Cancel'), $cancel_path),
    );
  }

  return $form;
}

/**
 * Validate callback for the organization create/edit form.
 *
 * @see organization_form()
 */
function organization_form_validate(&$form, &$form_state) {
  field_attach_form_validate('user', $form_state['user'], $form, $form_state);
}

/**
 * Submit callback for the organization create/edit form.
 *
 * @see organization_form()
 */
function organization_form_submit(&$form, &$form_state) {
  $org = $form_state['user'];

  if (isset($form_state['values']['name'])) {
    $org->name = $form_state['values']['name'];
  }
  if (isset($form_state['values']['mail'])) {
    $org->mail = $form_state['values']['mail'];
  }

  field_attach_submit('user', $org, $form, $form_state);
  user_save($org);

  drupal_set_message(t('The organization %name was saved.', array('%name' => $org->name)));

  $form_state['redirect'] = 'user/' . $org->uid;
}

/**
 * Form builder for deleting an organization.
 */
function organization_delete_form($form, &$form_state, $org) {
  $form_state['org'] = $org;
  $uri = organization_uri($org);

  return confirm_form(
    $form,
    t('Are you sure you want to delete the organization %name?', array('%name' => $org->name)),
    $uri['path'],
    NULL,
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Submit callback for deleting an organization.
 */
function organization_delete_form_submit(&$form, &$form_state) {
  $org = $form_state['org'];

  user_delete($org->uid);

  drupal_set_message(t('The organization %name was deleted.', array('%name' => $org->name)));

  if (!isset($_GET['destination'])) {
    $owner = organization_get_owner($org);
    $form_state['redirect'] = 'user/' . $owner->uid . '/organizations';
  }
}
