<?php

session_start();
$_SESSION['loggued_on_user'] = "";
$_SESSION['source']= "";
$_SESSION['adm']= false;
header('Location: index.php');
?>
