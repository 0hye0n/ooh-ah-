<?php
    fscanf(STDIN, "%d", $n);
    $data = fgets(STDIN);
    $sum=0;
    for($i=0; $i<$n; $i++)$sum+=$data[$i];
    echo $sum;
?>