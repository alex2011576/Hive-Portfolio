<?php

session_start();
$con = mysqli_connect($_SESSION["servername"], $_SESSION["login"], $_SESSION["password"]);
mysqli_select_db($con, 'rush00');

if (isset($_POST["add"])) {
	if (isset($_SESSION["cart"])) {
		$item_array_id = array_column($_SESSION["cart"], "product_id");
		if (!in_array($_GET["id"], $item_array_id)) {
			$count = count($_SESSION["cart"]);
			$item_array = array(
				"product_id" => $_GET["id"],
				"item_name" => $_POST["hidden_name"],
				"product_price" => $_POST["hidden_price"],
				"item_quantity" => $_POST["quantity"]
			);
			$_SESSION["cart"][$count] = $item_array;
		}	else {
			foreach ($_SESSION["cart"] as $key => &$item) {
				if ($item["product_id"] == $_GET["id"]) {
					$item["item_quantity"] += $_POST["quantity"];
				}
			}
		}
	} else {
		$item_array = array(
			"product_id" => $_GET["id"],
			"item_name" => $_POST["hidden_name"],
			"product_price" => $_POST["hidden_price"],
			"item_quantity" => $_POST["quantity"]
		);
		$_SESSION["cart"][0] = $item_array;
	}
}

$query = "SELECT * FROM products WHERE featured=6";
$featured = mysqli_query($con, $query);

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
	<nav>
		<select onChange="window.location.href=this.value" name="categories" id="categories">
			<option value="product_06360cam.php">360 cameras</option>
			<option value="product_01dslr.php">DSLR</option>
			<option value="product_02pocketcam.php">Pocket cameras</option>
			<option value="product_03instafilm.php">Instant & Film</option>
			<option value="product_04video.php">Video cameras</option>
			<option value="product_05action.php">Action cameras</option>
			<option value="product_07dashboard.php">Dashboard cameras</option>
			<option value="product_08trail.php">Trail cameras</option>
			<option value="product_09surveillance.php">Surveillance cameras</option>
			<option value="product_10webcam.php">Web cameras</option>
		</select>
	</nav>
	<div>
		<?php
		while ($product = mysqli_fetch_array($featured)) {

		?>
			<div>
				<p><?= $product["title"] ?></p>
				<img src="<?= $product["image"]; ?>" alt="<?= $product["title"]; ?>" />
				<p><?= $product["price"]; ?> €</p>
				<form method="post" action="product_06360cam.php?action=add&id=<?= $product["id"]; ?>">
					<input type="text" name="quantity" value="1">
					<input type="hidden" name="hidden_name" value="<?= $product["title"]; ?>">
					<input type="hidden" name="hidden_price" value="<?= $product["price"]; ?>">
					<input type="submit" name="add" value="Add to cart">
				</form>
			</div>
		<?php
		}
		?>
	</div>
</body>

</html>