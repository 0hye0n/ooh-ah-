<?php
    $data = array();
    fscanf(STDIN, "%d", $n);
    for($i = 0; $i<$n; $i++)
    {
        fscanf(STDIN, " %d", $temp);
        array_push($data, $temp);
    }
    sort($data);
    for($i = 0; $i<$n; $i++){echo $data[$i];echo "\n";}
?>