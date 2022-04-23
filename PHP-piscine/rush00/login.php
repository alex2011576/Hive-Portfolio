<?php
	include('auth.php');

	session_start();
	if ($_POST["login"] && $_POST["passwd"] && ($adm = auth($_POST["login"], $_POST["passwd"])) > 0)
	{
		$_SESSION["loggued_on_user"] = $_POST["login"];
		if ($adm === 2)
		{
			$_SESSION["adm"] = true;
		}
		if ($_SESSION["source"] === "cart")
		{
			$_SESSION["source"] = "";
			header('Location: validateorder.php');
			return ;
		}
		header('Location: index.php');
	}
	else
	{
		$_SESSION["loggued_on_user"] = "";
		//$_SESSION["wrong_pas"] = true;
		header('Location: login.html');
		return ;
	}
?>
