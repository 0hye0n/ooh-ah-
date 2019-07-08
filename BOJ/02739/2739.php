<?php
fscanf(STDIN, "%d", $n);
for($i = 1; $i<=9; $i++)fprintf(STDOUT, "%d * %d = %d\n", $n, $i, $i*$n);
?>