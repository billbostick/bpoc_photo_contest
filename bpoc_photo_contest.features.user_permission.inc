<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function bpoc_photo_contest_user_default_permissions() {
  $permissions = array();

  // Exported permission: create photo_submission content
  $permissions['create photo_submission content'] = array(
    'name' => 'create photo_submission content',
    'roles' => array(
      '0' => 'anonymous user',
    ),
  );

  // Exported permission: edit own photo_submission content
  $permissions['edit own photo_submission content'] = array(
    'name' => 'edit own photo_submission content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  return $permissions;
}
