<?php
/**
 * @file
 * Field and instance definitions for the Organization module.
 */

/**
 * Required field bases.
 *
 * @see field_create_field()
 *
 * @internal
 *
 * @return array
 *   An array of field definitions.
 */
function organization_required_field_bases() {
  $field_bases = array();

  // Exported field_base: 'organization_owner'
  $field_bases['organization_owner'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array('user'),
    'field_name' => 'organization_owner',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'sort' => array(
          'direction' => 'ASC',
          'property' => 'name',
          'type' => 'property',
        ),
        'target_bundles' => array(
          'user' => 'user',
        ),
      ),
      'target_type' => 'user',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}

/**
 * Required instances.
 *
 * @see field_create_instance()
 *
 * @internal
 *
 * @return array
 *   An array of field instance definitions.
 */
function organization_required_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-organization-organization_owner'
  $field_instances['user-organization-organization_owner'] = array(
    'bundle' => 'organization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'organization_owner',
    'label' => 'Owner',
    'required' => 1,
    'settings' => array(
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 30,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Owner');

  return $field_instances;
}
