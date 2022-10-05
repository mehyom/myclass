package edu.sswu.vm.io;

import edu.sswu.vm.Money;

public class ReturnBill extends ExchangeMoney<Money> {
	public ReturnBill() {
	}
	private static final ReturnBill instance = new ReturnBill();
	public static ReturnBill getInstance() {
		return instance;
	}
	@Override
	public void displayInputMessage() {
	}

	@Override
	public void input(Money money) {
		System.out.println(String.format(">> �����ȯ�� [%d] %s�� ��ȯ", money.getId(), money.getName() ));
	}

}
 