<?php
	fscanf(STDIN,"%d", $n);
	
	for($i = 0; $i<$n; $i++){
		
		for($k = 0; $k<$n-$i-1; $k++)
			printf(" ");
		
		for($j = 0; $j<$i+1; $j++)
			fprintf(STDOUT, "*");
		
		fprintf(STDOUT, "\n");
	}
?>