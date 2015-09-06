<div class="organization"<?php print $attributes; ?>>
  <?php if ($teaser): ?>
    <h3><a href="<?php print url($path); ?>"><?php print $name; ?></a></h3>
  <?php endif; ?>
  <?php print render($organization); ?>
</div>
