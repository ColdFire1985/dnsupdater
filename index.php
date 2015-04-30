<?php
# specify complete path to the include file if it's in another directory: 
include("dns-functions.inc");    
$newurl= "http://" . readIpFromFile() .":5000";
header("Location: $newurl");
?>