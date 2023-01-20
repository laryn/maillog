Maillog / Mail Developer
-------
Maillog provides an easy possibility to log all mails for debugging purposes.
It's possible to prevent the mails to being sent, so there is no need for an
extra mail server to test the mail functionality of other modules or Backdrop
core. Additionally you can immediately display the mail using the Devel module.

Features
--------------------------------------------------------------------------------
* All emails being sent by the site may have a copy stored in the database for
  later review.

* All email delivery may be halted, preventing a site from sending out emails
  in situations where that might not be needed, e.g. for a local development
  copy of the site.

* If the [Devel module](https://www.backdropcms.org/project/devel) is installed,
  emails can also be displayed on the page as they are being sent.

* If the [MailSystem module](https://www.backdropcms.org/project/mailsystem) is
  installed it is possible to control which of the installed email modules will
  be used to send messages from Maillog's settings page, mirroring MailSystem's
  functionality.

Configuration
--------------------------------------------------------------------------------
 1. On the User Accounts Permissions administration page ("Administer >> Configure
    >> People >> Permissions") there are three permissions to control:

    - The "Administer Maillog" permission allows users to access the settings
      page to control the module's options.

    - The "View Maillog" permission allows users to access the Maillog list page
      at admin/reports/maillog.

    - The "Delete Entries from the log" permission allows users to delete items
      from the log page.

 2. The main administrative page controls the module's settings page:
      admin/config/development/maillog


Troubleshooting / known issues
--------------------------------------------------------------------------------
If the email is not being logged then the site's default email system is not
configured correctly. It is recommended to use the MailSystem module
https://www.backdropcms.org/project/mailsystem to help with this. Alternatively, edit
the system.mail.json file in your active config folder:

```
  "default-system": "MaillogMailSystem",
```

Related modules
--------------------------------------------------------------------------------
Some similar modules that are available include:

* [Reroute Email](https://backdropcms.org/project/reroute_email)
  Reroutes outbound emails to a specific destination address.

Warning
-------

Recording mails may be in violation of some regional legal regulations. The
maintainers of this module deny all responsibility for how individual site
owners & maintainers use this module.

License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.

Current Maintainers
-------------------

- [Laryn Kragt Bakker](https://github.com/laryn)

Credits
-------

- Ported to Backdrop CMS by [herbdool](https://github.com/herbdool)
- This module is a port of the Maillog module for Drupal which was written and
  maintained by a large number of contributors, including:
  -  [Miro Dietiker](https://www.drupal.org/u/miro_dietiker)
  -  [Sascha Grossenbacher](https://www.drupal.org/u/berdir)
  -  [Damien McKenna](https://www.drupal.org/u/damiemckenna)
