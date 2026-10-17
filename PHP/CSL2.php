<?php
show_source(__FILE__);
include('flag.php');
$a=$_GET['a'];
$b=$_GET['b'];
$c=$_GET['c'];

$shiki = is_numeric($a) and preg_match('/^[a-z0-9]+$/i',$b);
if ($shiki==1) {
    if (intval($b) == 'summer') {
        if (strpos($b, "0")==0) {
            die('Denied!');
        } else {
            $$c = $a;
            parse_str($b, $pockets);
            if ($pockets[$summer] == md5($c)) {
                echo $flag;
            }
        }
    } else {
        die('Denied!');
    }
} else {
    die('Denied!');
}