package edu.sswu.vm;

class MoneyModel extends Money {
	boolean isCoin;
	public MoneyModel(int id, String name, int faceValue, boolean isCoin) {
		super(id, name, faceValue);
		this.isCoin = isCoin;
	}
	@Override
	public int realValue() {
		return 0;
	}
	public boolean isCoin() {
		return isCoin;
	}
};