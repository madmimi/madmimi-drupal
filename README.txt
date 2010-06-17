$Id: README.txt,v 1.2 2010/05/31 21:13:08 elliotttt Exp $

-- SUMMARY --

The Mad Mimi module provides mail integration with 3rd party mail
service, Mad Mimi. Currently it just over-rides all email sent 
from Drupal and sends it via Mad Mimi. Future releases may include 
additional options for sending specific types of email.

-- INSTALLATION --

Before enabling the module, grab a copy of the PHP MadMimi class
from http://github.com/madmimi/php-api-client

The currently supported version is 2.x

Create a new folder in your madmimi module folder called classes.
Place the MadMimi.class.php and Spyc.class.php files in here.

The full location should be something like:
/path/to/drupal/sites/all/modules/madmimi/classes/MadMimi.class.php

Add the following to your /sites/default/settings.php file:
$conf['smtp_library'] = 'sites/all/modules/madmimi/madmimi.mail.inc';

-- ONE MORE THING BEFORE YOU SEND --

So, it's great that you've got this far in the installation process. Congrats. :)
However, there's one more thing you'll want to do if you're using the Composer promotion type
(see the admin screen for info). Create a promotion and inside it, place this: {body} . 
When you send, Drupal will replace that placeholder with your text. Sweet, huh?

If you're using plain text, no worries. Just fire and forget.

-- CREDITS --
Written by elliotttt, sponsored by The SuperGroup
www.thesupergroup.com

BIG THANKS to Nicholas Young and the whole Mad Mimi team, without
their tireless support, this module would not be so easy to get
up and running.
www.madmimi.com