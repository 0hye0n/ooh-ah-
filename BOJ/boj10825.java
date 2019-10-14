package Practice;

import java.io.*;
import java.util.*;

class Score
{
	String name;
	int lang, eng, math;
	
	public Score(String name, int lang, int eng, int math)
	{
		this.name = name;
		this.lang = lang;
		this.eng = eng;
		this.math = math;
	}
}


class Cmp1 implements Comparator<Score>
{
	public int compare(Score a, Score b)
	{
		int res = a.name.compareTo(b.name);

		if(a.lang > b.lang) return -1;
		else if(a.lang < b.lang) return 1;
		else
		{
			if(a.eng > b.eng) return 1;
			else if(a.eng < b.eng) return -1;
			else
			{
				if(a.math > b.math) return -1;
				else if(a.math < b.math) return 1;
				else
				{
					if(res == 0) return 0;
					else if(res > 0) return 1;
					else return -1;
				}
			}
		}
		
		
	}
}


public class boj10825 {

	public static void main(String[] args) throws IOException{
	
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	int n = Integer.parseInt(br.readLine());
	ArrayList<Score> score = new ArrayList<Score>();


	for(int i = 0; i < n; i++)
	{
		String s = br.readLine();
		StringTokenizer st = new StringTokenizer(s);
		
		String name = st.nextToken();
		int lang = Integer.parseInt(st.nextToken());
		int eng = Integer.parseInt(st.nextToken());
		int math = Integer.parseInt(st.nextToken());
		
		score.add(new Score(name, lang, eng, math));
	}
	
	score.sort(new Cmp1());
	
	for(int i = 0; i < n; i++)
	{
		bw.write(score.get(i).name + "\n");
	}
	
	bw.flush();
	br.close();
	bw.close();
	}
}
