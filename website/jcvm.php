<?php

// Set up custom error handler
error_reporting(0);
set_error_handler("error_handler");
function error_handler($errno, $errstr, $errfile, $errline)
{
  switch ($errno) {
  case E_USER_FATAL:
    echo "<b>FATAL</b> [$errno] $errstr<br />\n";
    echo "  Fatal error in line $errline of file $errfile";
    echo ", PHP ".PHP_VERSION." (".PHP_OS.")<br />\n";
    echo "Aborting...<br />\n";
    exit(1);
    break;
  case E_USER_ERROR:
  case E_ERROR:
    echo "<b>ERROR:</b> [$errno] $errstr<br />\n";
    break;
  case E_USER_WARNING:
  case E_WARNING:
    echo "<b>WARNING:</b> [$errno] $errstr<br />\n";
    break;
  case E_USER_NOTICE:
  case E_NOTICE:
    echo "<b>NOTICE:</b> [$errno] $errstr<br />\n";
    break;
  default:
    echo "Unkown error type: [$errno] $errstr<br />\n";
    break;
  }
}

// Header output function
function jcvm_header($title)
{
	?><!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN"
          "http://www.w3.org/TR/REC-html40/loose.dtd">
<html>
<head>
<title>JC Virtual Machine: <?php echo htmlspecialchars($title); ?></title>
</head>
<?php require("style.php"); ?>
<body bgcolor="#FFFFFF">
<table border="0" cellpadding="0" cellspacing="0" width="100%" align="center">
  <tr valign="bottom" height="60">
    <td align="left" valign="top" rowspan="2">
      <a href="http://jcvm.sourceforge.net/">
        <img border="0" width="60" height="60" src="jc.png"></a></td>
    <td>
      <table border="0" cellpadding="0" cellspacing="0" width="100%" height="100%">
        <tr><td align="right" class="title">JC Virtual Machine</td></tr>

      </table>
    </td>
  </tr>
</table>
<hr size="1" noshade width="100%"/>
<?php

register_shutdown_function("jcvm_footer");

}

// Footer output function
function jcvm_footer()
{
?>
<br/>
<div align="right">
Hosted by:&nbsp;
<a href="http://sourceforge.net/">
<img border="0" src="http://sourceforge.net/sflogo.php?group_id=102198"></a>
</div>
<hr size="1" noshade width="100%"/>
</body></html>
<?php
}

