<?php
	session_start();
?>
<html>

<body>
	<h2> Install Database </h2>
	<form method="GET">
		Servername: <input type="text" name="servername" value="localhost" required />
		<br />
		Username: <input type="text" name="login" value="root" required />
		<br />
		Password: <input type="password" name="password" required />
		<input type="submit" name="submit" value="OK" />
	</form>
	<?php
	$database = "rush00";
	if (!$_GET["servername"] || !$_GET["login"] || !$_GET["password"]) {
		echo "Please tell where to store the MySQL database" . " \n";
		return;
	}
	$servername = $_GET["servername"];
	$username = $_GET["login"];
	$password = $_GET["password"];
	$_SESSION["servername"] = $_GET["servername"];
	$_SESSION["login"] = $_GET["login"];
	$_SESSION["password"] = $_GET["password"];
	echo "Trying to connect to database...<br />";
	$con = mysqli_connect($servername, $username, $password);
	if ($con === false) {
		echo "Sorry, that's not a correct password" . " \n";
		return;
	}
	echo "Connection successful!<br />";
	echo "Recreating database...<br />";
	$sql = "DROP DATABASE IF EXISTS $database";
	mysqli_query($con, $sql);
	echo "Trying to create new database called: $database<br />";
	$sql = "CREATE DATABASE IF NOT EXISTS $database";
	mysqli_query($con, $sql);
	mysqli_select_db($con, $database);
	$sql = "CREATE TABLE `products` (
				`id` int(11) NOT NULL,
				`title` varchar(255) NOT NULL,
				`price` decimal(10,2) NOT NULL,
				`brandname` varchar(100) NOT NULL,
				`image` varchar(255) NOT NULL,
				`description` text NOT NULL,
				`featured` tinyint(4) NOT NULL
			  ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4";
	mysqli_query($con, $sql);
	$sql = "ALTER TABLE `products`
				ADD PRIMARY KEY (`id`)";
	mysqli_query($con, $sql);
	$sql = "ALTER TABLE `products`
				MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=32";
	mysqli_query($con, $sql);
	$sql = "CREATE TABLE `users` (
				`id` int(11) NOT NULL,
				`username` text NOT NULL,
				`password` text NOT NULL
			  ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4";
	mysqli_query($con, $sql);
	$sql = "CREATE TABLE `orders` (
		`user` text NOT NULL,
		`item_name` text NOT NULL,
		`product_price` text NOT NULL,
		`quantity` text NOT NULL,
		`total` text NOT NULL
	  ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4";
	mysqli_query($con, $sql);
	echo "Adding items to database...<br />";
	$sql = "INSERT INTO `products` (`id`, `title`, `price`, `brandname`, `image`, `description`, `featured`) VALUES
			(3, 'Canon EOS R6 body', '2699.00', 'Canon', '/rush00/images/cameras/01dslr/canoneosr6.jpg', '', 1),
			(4, 'Sony A7S III body', '4389.00', 'Sony', '/rush00/images/cameras/01dslr/sonya7siii.jpg', '', 1),
			(5, 'Nikon Coolpix P1000 Superzoom', '1079.00', 'Nikon', '/rush00/images/cameras/01dslr/nikoncoolpixp1000.jpg', '', 1),
			(6, 'Sony RX100 VII digital camera', '1269.00', 'Sony', '/rush00/images/cameras/02pocketcam/sonyrx100vii.jpg', '', 2),
			(7, 'Ricoh GR III digital camera', '819.00', 'Ricoh', '/rush00/images/cameras/02pocketcam/ricohgriii.jpg', '', 2),
			(8, 'Canon Powershot G5 X Mark II', '899.00', 'Canon', '/rush00/images/cameras/02pocketcam/canonpowershotg5x.jpg', '', 2),
			(9, 'Fujifilm Instax Mini LiPlay', '179.00', 'Fujifilm', '/rush00/images/cameras/03instafilm/fujifilminstaxmini.jpg', '', 3),
			(10, 'Lomography Konstruktor - \"Assemble Yourself Camera\"', '39.90', 'Lomography', '/rush00/images/cameras/03instafilm/lomographykonstruktor.jpg', '', 3),
			(11, 'Polaroid Originals SX-70 Original', '389.00', 'Polaroid', '/rush00/images/cameras/03instafilm/polaroidoriginals.jpg', '', 3),
			(12, 'Blackmagic Pocket Cinema Camera 4K', '1349.00', 'Blackmagic', '/rush00/images/cameras/04video/bmpocketcinema.jpg', '', 4),
			(13, 'Sony Handycam HDR-CX240', '229.00', 'Sony', '/rush00/images/cameras/04video/sonyhandycamcx240.jpg', '', 4),
			(14, 'Panasonic HC-VX1', '699.00', 'Panasonic', '/rush00/images/cameras/04video/panasonichcvx1.jpg', '', 4),
			(15, 'GoPro Hero 10 Black', '499.90', 'GoPro', '/rush00/images/cameras/05action/goprohero10black.jpg', '', 5),
			(16, 'DJI Osmo Action + filter set', '369.00', 'DJI', '/rush00/images/cameras/05action/djiosmoaction.jpg', '', 5),
			(17, 'Insta360 ONE RS 4K Boost', '349.00', 'Insta360', '/rush00/images/cameras/05action/insta360oners4k.jpg', '', 5),
			(18, 'Insta360 Air 360 camera for Android', '169.90', 'Insta360', '/rush00/images/cameras/06360cam/insta360air360.jpg', 'Insta360', 6),
			(19, 'Kandao Meeting 360 All-In-One Conferencing', '729.00', 'Kandao', '/rush00/images/cameras/06360cam/kandaomeeting360.jpg', '', 6),
			(20, 'Ricoh Theta X 360', '1090.00', 'Ricoh', '/rush00/images/cameras/06360cam/ricohthetax360.jpg', '', 6),
			(21, 'Blackvue DR750X-1CH Plus', '319.00', 'Blackvue', '/rush00/images/cameras/07dashboard/blackvuedr750x.jpg', '', 7),
			(22, 'Blackvue DR900X-2CH Plus 4K (Front & back cameras)', '549.00', 'Blackvue', '/rush00/images/cameras/07dashboard/blackvuedr900x.jpg', '', 7),
			(23, 'Transcend DrivePro 250 GPS', '104.90', 'Transcend', '/rush00/images/cameras/07dashboard/transcenddrivepro.jpg', '', 7),
			(24, 'Burrel Edge HD trail camera', '129.00', 'Burrel', '/rush00/images/cameras/08trail/burreledgehd.jpg', '', 8),
			(25, 'Burrel S12HD + SMS III', '199.00', 'Burrel', '/rush00/images/cameras/08trail/burrels12hd.jpg', '', 8),
			(26, 'Burrel Edge Security Box protector', '34.90', 'Burrel', '/rush00/images/cameras/08trail/burreledgesecurity.jpg', '', 8),
			(27, 'Brinno TLC200 PRO TimeLapse', '219.00', 'Brinno', '/rush00/images/cameras/09surveillance/BrinnoTLC200.jpg', '', 9),
			(28, 'Brinno TLC2020 TimeLapse', '419.00', 'Brinno', '/rush00/images/cameras/09surveillance/BrinnoTLC2020.jpg', '', 9),
			(29, 'Logitech Brio 4K webcam', '249.00', 'Logitech', '/rush00/images/cameras/10webcam/logitechbrio4k.jpg', '', 10),
			(30, 'Logitech C930e', '159.00', 'Logitech', '/rush00/images/cameras/10webcam/logitechc930e.jpg', '', 10),
			(31, 'Kandao Meeting Pro 360 All-In-One', '849.00', 'Kandao', '/rush00/images/cameras/10webcam/kandaomeetingpro.jpg', '', 10)";
	mysqli_query($con, $sql);
	echo "Database ready!<br /><br />";
	?>
	<a href="index.php">
		<button type="button">Move to Web Store</button>
	</a>
</body>

</html>