<?php
# name of the file where the IP address will be stored: 
$ip_file = "./ip";

# write debug stuff to a logfile
function message($text) {
  $fname = "dyndns.log";
  $file_size = filesize($fname);
  $datum = date("Y-m-d H:i:s");
  if ($file_size > 2097152)
  {
	$counter = 0;
       while(file_exists($fname)) {
        $fname = $fname . $counter . '.log';
        $counter++;
    };
  }
  $file = fopen("dyndns.log", "w");
  #$file = fopen("dyndns.log", "a");
  $text = $datum ." " .$text;
  fwrite($file, $text);
  fclose($file);
}

# get IP address from request parameter, or if none is given, 
# from the REMOTE_ADDR parameter
function getIpFromRequest() {
  # just in case the IP is in the request parameters, you never know: 
  if (isset($_GET["ip"])) {
    return $_GET["ip"];
  } 
  if (isset($_POST["ip"])) {
    return $_POST["ip"];
  } 
  # if it's not, we get it from the remote address parameter: 
  return $_SERVER["REMOTE_ADDR"];
}

# read the IP address from the file. 
function readIpFromFile() {
  global $ip_file;
  if(file_exists($ip_file)) {
    if(filesize($ip_file)>0) {
      $file = fopen($ip_file, "r");
      $ip = fread($file, filesize($ip_file));
      fclose($file);
      return $ip;
    }
  }
}

# write the IP to the file. will return 'false' if there is a problem. 
function writeIpToFile()     {
  global $ip_file;
  $file = fopen($ip_file, "w");
  $result = fwrite($file, getIpFromRequest());
  fclose($file);
  return result;
}
?>