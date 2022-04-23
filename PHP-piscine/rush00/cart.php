<?php
include('auth.php');
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

if (isset($_GET["action"])) {
	if ($_GET["action"] == "delete") {
		foreach ($_SESSION["cart"] as $key => $value) {
			if ($value["product_id"] == $_GET["id"]) {
				unset($_SESSION["cart"][$key]);
			}
		}
	}
}

$query = "SELECT * FROM products ORDER BY id ASC";
$result = mysqli_query($con, $query);
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
		<?php
		if (mysqli_num_rows($result) > 0) {
			while ($row = mysqli_fetch_array($result)) {

		?>
				<div>
			<?php
			}
		}
			?>
			<table>
				<tr>
					<th>Product Name</th>
					<th>Quantity</th>
					<th>Price</th>
					<th>Total Price</th>
					<th>Remove Item</th>
				</tr>

				<?php
				if (!empty($_SESSION["cart"])) {
					$total = 0;
					foreach ($_SESSION["cart"] as $key => $value) {
				?>
						<tr>
							<td><?= $value["item_name"]; ?></td>
							<td><?= $value["item_quantity"]; ?></td>
							<td><?= $value["product_price"]; ?> €</td>
							<td><?= number_format($value["item_quantity"] * $value["product_price"], 2); ?> €</td>
							<td><a href="cart.php?action=delete&id=<?= $value["product_id"]; ?>">Remove Item</a></td>
						</tr>
						<?php
						$total = $total + ($value["item_quantity"] * $value["product_price"]);
						?>
					<?php
					}
					?>
					<tr>
						<td>Total</td>
						<th><?= number_format($total, 2); ?> €</th>
						<td></td>
					</tr>
				<?php
				}
				if ($_SESSION["loggued_on_user"]) {
				?>
			</table>
			<a href="validateorder.php">
				<button type="button">Validate order</button>
			</a>
			<?php
				} else {
				$_SESSION["source"] == "cart"	?>
				</table>
				<a href="login.php">
					<button type="button">Validate order</button>
				</a>
				<?php
					}
				?>
				</div>
	</div>
</body>

</html>