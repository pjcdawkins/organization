<?php
/**
 * @file
 * Default Views for the Organization module.
 */

/**
 * Implements hook_views_default_views().
 */
function organization_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'organizations';
  $view->description = 'A list of organizations';
  $view->tag = 'organization';
  $view->base_table = 'users';
  $view->human_name = 'Organizations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Organizations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: User: Name (organization_name) */
  $handler->display->display_options['sorts']['organization_name_value']['id'] = 'organization_name_value';
  $handler->display->display_options['sorts']['organization_name_value']['table'] = 'field_data_organization_name';
  $handler->display->display_options['sorts']['organization_name_value']['field'] = 'organization_name_value';
  /* Contextual filter: User: Owner (organization_owner) */
  $handler->display->display_options['arguments']['organization_owner_target_id']['id'] = 'organization_owner_target_id';
  $handler->display->display_options['arguments']['organization_owner_target_id']['table'] = 'field_data_organization_owner';
  $handler->display->display_options['arguments']['organization_owner_target_id']['field'] = 'organization_owner_target_id';
  $handler->display->display_options['arguments']['organization_owner_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['organization_owner_target_id']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['organization_owner_target_id']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['organization_owner_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['organization_owner_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['organization_owner_target_id']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/organizations';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Organizations';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views[$view->name] = $view;

  return $views;
}