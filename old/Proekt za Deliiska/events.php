<!DOCTYPE html>
<html>

<head>
	<title>Събития</title>
	<style>
		html {
			background: url("bg.png") no-repeat center center fixed;
			background-size: cover;
		}

		body {
			font-family: Arial, sans-serif;
		}

		h1 {
			text-align: center;
			margin-top: 50px;
			margin-bottom: 30px;
			color: #333333;
		}

		h2 {
			color: #333333;
			margin-top: 30px;
			text-align: center;
		}

		form {
			width: 50%;
			margin: 0 auto;
			background-color: #ffffff;
			padding: 20px;
			border-radius: 5px;
			box-shadow: 0px 2px 5px rgba(0, 0, 0, 0.3);
		}

		form label {
			display: block;
			margin-bottom: 10px;
			color: #333333;
		}

		form input[type="date"],
		form input[type="text"] {
			padding: 10px;
			border: none;
			border-radius: 5px;
			box-shadow: 0px 1px 3px rgba(0, 0, 0, 0.1);
			width: 100%;
			margin-bottom: 20px;
			font-size: 16px;
			color: #333333;
		}

		form input[type="submit"] {
			background-color: #333333;
			color: #ffffff;
			padding: 10px 20px;
			border: none;
			border-radius: 5px;
			font-size: 16px;
			cursor: pointer;
		}

		form input[type="submit"]:hover {
			background-color: #4c4c4c;
		}

		ul {
			list-style: none;
			padding: 0;
			margin: 0;
			width: 50%;
			margin: 0 auto;
			background-color: #ffffff;
			padding: 20px;
			border-radius: 5px;
			box-shadow: 0px 2px 5px rgba(0, 0, 0, 0.3);
		}

		li {
			margin-bottom: 10px;
			color: #333333;
		}

		li:before {
			content: "";
			display: inline-block;
			height: 20px;
			width: 20px;
			background-image: url("icon.png");
			background-size: contain;
			margin-right: 10px;
			vertical-align: middle;
		}
	</style>
</head>

<body>
	<h1>Събития</h1>

	<?php
	if (isset($_POST['submit'])) {
		$date = $_POST['date'];
		$event = $_POST['event'];

		$file = fopen("events.txt", "a");

		fwrite($file, $date . " | " . $event . "\n");

		fclose($file);
	}
	?>

	<form method="post">
		<h2>Ново Събитие</h2>
		<br>
		<label for="date">Дата:</label>
		<input type="date" name="date" required>
		<label for="event">Събитие:</label>
		<input type="text" name="event" required><br><br>
		<input type="submit" name="submit" value="Добави">
	</form>

	<ul>
		<?php
		$file = fopen("events.txt", "r");

		while (!feof($file)) {
			$line = fgets($file);

			$parts = explode(" | ", $line);

			if (count($parts) >= 2) {
				echo "<li>" . $parts[0] . " - " . $parts[1] . "</li>";
			}
		}


		fclose($file);
		?>
	</ul>