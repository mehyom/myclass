package edu.sswu.vm;

public class Coin extends Money {
	private int count;
	public Coin(int id, String name, int faceValue, int count) {
		super(id, name, faceValue);
		this.count = count;
	}
	@Override
	public int realValue() {
		return count * faceValue;
	}
	public void addCount(int adjust) {
		count += adjust;
	}
	public int getCount() {
		return count;
	}
}
