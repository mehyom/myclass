package edu.sswu.vm;

public class TransactionManager extends Cash {
	private Product item;
	public TransactionManager() {
	}
	void setItem(Product item) {
		this.item = item;
	}
	void inputMoney(Money money) {
		super.credits(money);
	}
	void releaseCash() {
		super.debits();
	}
	int getChange() {
		return super.amount();
	}
	public Cash getCash() {
		return this;
	}
	
}
