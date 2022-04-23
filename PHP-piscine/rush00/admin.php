<?php
include('auth.php');
session_start();
$con = mysqli_connect($_SESSION["servername"], $_SESSION["login"], $_SESSION["password"]);
mysqli_select_db($con, 'rush00');

$query = "SELECT * FROM orders ORDER BY user ASC";
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
				<a href="index.php"><img id="logo" src="images/logo1.png" alt="LOGO" title="LOGO"></a>
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
					<img class="small" src="images/basket.jpeg">
				</a>
			</div>
		</div>
		<?php if (isset($_SESSION["loggued_on_user"]) && $_SESSION["loggued_on_user"] !== "") : ?>
			<menu id="usr_link1">
				Username: <a href="profile.php"> <?php echo $_SESSION["loggued_on_user"]; ?></a>
				<a href="logout.php"> <button id="logout" type="button"> logout</button></a>
			</menu>
		<?php else : ?>
			<form name="login.php" action="login.php" method="post">
				Username: <br />
				<input type="text" name="login" value="" />
				<br />
				Password: <br />
				<input type="password" name="passwd" value="" /><br />
				<input id="ok_button" type="submit" name="submit" value="OK" />
			</form>
		<?php endif ?>

	</div>
	<div>
			<div>
			<h1>Orders</h1>
			<table>
				<tr>
					<th>User</th>
					<th>Product</th>
					<th>Price</th>
					<th>Quantity</th>
					<th>Item total</th>
				</tr>

				<?php
				if (mysqli_num_rows($result) > 0) {
					while ($row = mysqli_fetch_array($result)) {
				?>
						<tr>
							<td><?= $row["user"]; ?></td>
							<td><?= $row["item_name"]; ?></td>
							<td><?= $row["product_price"]; ?> €</td>
							<td><?= $row["quantity"]; ?></td>
							<td><?= $row["total"]; ?></td>
						</tr>
						<?php
						$total = $total + ($value["item_quantity"] * $value["product_price"]);
						?>
					<?php
					}
					?>
					<!-- <tr>
						<td>Total</td>
						<th><?= number_format($total, 2); ?> €</th>
						<td></td>
					</tr> -->
				<?php
				}
				?>
				</div>
	</div>
</body>

</html>