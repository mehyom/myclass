package edu.sswu.vm;

import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Utils {
	@SafeVarargs
	public static <T> Set<T> toSet(T... objs) {
	    Set<T> set = new HashSet<T>();
	    Collections.addAll(set, objs);
	    return set;
	}
	static Utils thisInstance = new Utils();
	Scanner ui = new Scanner(System.in);
	
	public static int scanNumber() {
		String line = thisInstance.ui.nextLine();
		
		if (line.compareToIgnoreCase("X")==0) {
			throw new ReturnMoneyException();
		}
		return Integer.parseInt(line);
	}
}
