<!DOCTYPE html>
<html style="height: 100%;">
<head>
<title>Регистрация</title>
<!-- Latest compiled and minified CSS -->
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">

<!-- jQuery library -->
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.3/jquery.min.js"></script>

<!-- Latest compiled JavaScript -->
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
</head>
<body style="min-height: 100%;">
<div class="container" style="min-height: 100vh;">
	
<!-- Button trigger modal -->
<button type="button" class="btn btn-primary" data-toggle="modal" data-target="#exampleModal">
  Launch demo modal
</button>

<!-- Modal -->
<div class="modal fade" id="exampleModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <h5 class="modal-title" id="exampleModalLabel">Регистрация</h5>
        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
          <span aria-hidden="true">&times;</span>
        </button>
      </div>
      <div class="modal-body">
              <form action="register.php" method="post">
  <!-- Email input -->
  <div class="form-outline mb-4">
    <label class="form-label" for="name">Име</label>
    <input type="text" id="name" name="name" class="form-control" placeholder="Име"/>
  </div>

	</br>
	
  <!-- Password input -->
  <div class="form-outline mb-4">
    <label class="form-label" for="password">Парола</label>
    <input type="password" id="password" name="password" class="form-control" placeholder="Парола"/>
  </div>

	</br>

  <!-- Submit button -->
  <button type="submit" class="btn btn-primary btn-block mb-4">Регистрация</button>

  <!-- Register buttons -->
  <div class="text-center">
    <p>Имате профил? <a href="./index.php">Влезни</a></p>
  </div>
</form>
      </div>
      
    </div>
  </div>
</div>


</div>

<?php
$username="root";
$password="";
$database="alumni";

$mysqli = new mysqli("localhost", $username, $password, $database);
$mysqli->select_db($database) or die( "Unable to select database");
$conn = mysqli_connect("localhost", $username, $password, $database);
if (isset($_POST['name'], $_POST['password'])) {
	$name = $_POST['name'];
	$pass = $_POST['password'];
$sql = "INSERT INTO user(username, password) VALUES ('".$name."','".$pass."');";
	if ($conn->query($sql) === TRUE) {
	  echo "New record created successfully";
	} else {
	  echo "Error: " . $sql . "<br>" . $conn->error;
	}

}
 

$conn->close();

?>
</div>
</body>
</html>
