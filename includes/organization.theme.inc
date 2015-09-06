<?php
/**
 * @file
 * Theme functions for the Organization module.
 */

/**
 * Theme preprocess function for organizations.
 */
function template_preprocess_organization(&$variables) {
  $org = $variables['elements']['#account'];

  // Add an $organization variable for templates.
  foreach (element_children($variables['elements']) as $key) {
    $variables['organization'][$key] = $variables['elements'][$key];
  }

  // Preprocess fields.
  field_attach_preprocess('user', $org, $variables['elements'], $variables);

  $variables['teaser'] = $variables['elements']['#view_mode'] === 'teaser';
  $variables['name'] = check_plain(organization_get_name($org));
  $variables['path'] = 'organization/' . $org->uid;
}
