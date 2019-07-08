<?php
	fscanf(STDIN,"%d", $n);
	
	for($i = 0; $i<$n; $i++){
		for($j = 0; $j<$i+1; $j++)
			fprintf(STDOUT, "*");
		
		fprintf(STDOUT,"\n");
	}
?>