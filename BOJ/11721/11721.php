<?php
$data = fgets(STDIN);
$len = strlen($data);
for($i = 0; $i<$len; $i++)
{
    echo $data[$i];
    if(($i+1)%10==0)echo"\n";

}
?>
