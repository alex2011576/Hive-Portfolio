<?php
session_start();
$con = mysqli_connect($_SESSION["servername"], $_SESSION["login"], $_SESSION["password"]);
mysqli_select_db($con, 'rush00');

if ($_SESSION["loggued_on_user"]) {
	foreach ($_SESSION["cart"] as $key => $value) {
		$sql = "INSERT INTO `orders` (`user`, `item_name`, `product_price`, `quantity`, `total`) VALUES	('".$_SESSION["loggued_on_user"]."','".$value["item_name"]."','".$value["product_price"]."','".$value["item_quantity"]."','".number_format($value["item_quantity"] * $value["product_price"], 2)."')";
		mysqli_query($con, $sql);
	}
}

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
	<link rel="preconnect" href="https://fonts.googleapis.com">
	<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
	<link href="https://fonts.googleapis.com/css2?family=Roboto:wght@300&display=swap" rel="stylesheet">
    <title>RUSH00</title>
    <link rel="stylesheet" href="index.css">
</head>
<body>
    <div class="top">
		<div id="top_split">
			<div id="top_bars">
				<a href="index.php"><img id="logo" src="images/logo1.png"	alt="LOGO" title="LOGO"></a>
				<a href="product_01dslr.php">
					<button type="button">SHOP</button>
				</a>
				<br />
				<a href="profile.php">
					<button type="button">PROFILE</button>
				</a>
				<br />
			</div>
			<div id="wrappertop">
					<a href="cart.php">
						<img class="small" src="images/basket.jpeg"	>
					</a>
					<?php
						//<a class="small" href="http://www.disney.com">
						//	<img class="small" src="images/reload.png"
						//	alt="Start from the beginning" title="Start from the beginning">
						//</a>
						//<a class="small" href="http://www.relaischateaux.com">
						//	<img class="small" src="images/close.gif"
						//	alt="Disconnect" title="Disconnect">
						//</a>
					?>
			</div>
		</div>
        <?php if(isset($_SESSION["loggued_on_user"]) && $_SESSION["loggued_on_user"] !==""): ?>
            <menu id="usr_link1">
                            Username: <a href="profile.php">  <?php echo $_SESSION["loggued_on_user"]; ?></a>
                            <a href="logout.php"> <button id="logout" type="button"> logout</button></a>
            </menu>
        <?php else: ?>
            <form name="login.php" action="login.php" method="post">
    		Username: <br />
			<input type="text" name="login" value="" />
    		<br />
    		Password: <br />
			<input type="password" name="passwd" value="" /><br />
    		<input id ="ok_button" type="submit" name="submit" value="OK"/>
    	    </form>
        <?php endif ?>

    </div>
	<div style="width:1400px; margin-left:auto; margin-right:auto; margin-top:100px;">
	<h1>ORDER VALIDATED!</h1>
	</div>
</body>

</html>