(function () {
  function initialiseNavigation() {
    var toggle = document.querySelector('[data-nav-toggle]');
    var menu = document.getElementById('topmenu');

    if (!toggle || !menu) {
      return;
    }

    var icon = toggle.querySelector('[data-nav-toggle-icon]');

    function setNavigationOpen(isOpen) {
      menu.classList.toggle('is-open', isOpen);
      toggle.setAttribute('aria-expanded', String(isOpen));

      if (icon) {
        icon.textContent = isOpen ? '-' : '+';
      }
    }

    toggle.addEventListener('click', function () {
      setNavigationOpen(toggle.getAttribute('aria-expanded') !== 'true');
    });

    menu.addEventListener('click', function (event) {
      if (event.target.closest('a')) {
        setNavigationOpen(false);
      }
    });

    document.addEventListener('keydown', function (event) {
      if (event.key === 'Escape' && toggle.getAttribute('aria-expanded') === 'true') {
        setNavigationOpen(false);
        toggle.focus();
      }
    });
  }

  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', initialiseNavigation);
  } else {
    initialiseNavigation();
  }
}());
