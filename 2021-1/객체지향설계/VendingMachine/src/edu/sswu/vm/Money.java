package edu.sswu.vm;

public abstract class Money {
	final protected int id;
	final protected String name;
	final protected int faceValue;
	public Money(int id, String name, int faceValue) {
		this.id = id;
		this.name = name;
		this.faceValue = faceValue;
	}
	abstract public int realValue();
	public int getId() {
		return id;
	}
	public String getName() {
		return name;
	}
	public int getFaceValue() {
		return faceValue;
	}
}
