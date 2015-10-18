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
  $view->name = 'organization_admin';
  $view->description = t('An administrative list of organizations');
  $view->tag = 'organization';
  $view->base_table = 'users';
  $view->human_name = t('Organizations admin');
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = t('Organizations');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'organization: administer';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'organization_name' => 'organization_name',
    'name' => 'name',
    'created' => 'created',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'organization_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['organization_owner_target_id']['id'] = 'organization_owner_target_id';
  $handler->display->display_options['relationships']['organization_owner_target_id']['table'] = 'field_data_organization_owner';
  $handler->display->display_options['relationships']['organization_owner_target_id']['field'] = 'organization_owner_target_id';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'ID';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['organization_name']['id'] = 'organization_name';
  $handler->display->display_options['fields']['organization_name']['table'] = 'field_data_organization_name';
  $handler->display->display_options['fields']['organization_name']['field'] = 'organization_name';
  $handler->display->display_options['fields']['organization_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['organization_name']['alter']['path'] = 'user/[uid]';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'organization_owner_target_id';
  $handler->display->display_options['fields']['name']['label'] = t('Owner');
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Filter criterion: User: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'users';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = 'organization';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: User: Name (organization_name) */
  $handler->display->display_options['filters']['organization_name_value']['id'] = 'organization_name_value';
  $handler->display->display_options['filters']['organization_name_value']['table'] = 'field_data_organization_name';
  $handler->display->display_options['filters']['organization_name_value']['field'] = 'organization_name_value';
  $handler->display->display_options['filters']['organization_name_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['organization_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['organization_name_value']['expose']['operator_id'] = 'organization_name_value_op';
  $handler->display->display_options['filters']['organization_name_value']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['organization_name_value']['expose']['operator'] = 'organization_name_value_op';
  $handler->display->display_options['filters']['organization_name_value']['expose']['identifier'] = 'organization_name_value';
  $handler->display->display_options['filters']['organization_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'organization_owner_target_id';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = t('Owner');
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/people/organizations';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Organizations';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'organization_user';
  $view->description = t("A list of the user's organizations");
  $view->tag = 'organization';
  $view->base_table = 'users';
  $view->human_name = t("User's organizations");
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = t('Organizations');
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
  /* Filter criterion: User: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'users';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = 'organization';

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
