<?php
# this include file contains some helper functions: 
include("dns-functions.inc");    

if ( readIpFromFile() == getIpFromRequest()) {
  header("HTTP/1.1 304 IP address didn't change", true, 304);
  message("no change in IP, address is " . getIpFromRequest() . "\n");
} else {
  if (writeIpToFile()){
    header("HTTP/1.0 200 OK", true, 200);
    message("change successful, new address is " . getIpFromRequest() . "\n");
  } else {
    header("HTTP/1.0  500 Error writing file or similar", true, 500);
    message("error writing file or other.\n");
    exit;
  }
}
?>