package edu.sswu.vm.io;

import edu.sswu.vm.Money;

public class ReturnCoin extends ExchangeMoney<Money> {
	public ReturnCoin() {
	}
	private static final ReturnCoin instance = new ReturnCoin();
	public static ReturnCoin getInstance() {
		return instance;
	}
	@Override
	public void displayInputMessage() {
	}

	@Override
	public void input(Money money) {
		System.out.println(String.format(">> ������ȯ�� [%d] %s ���� %d�� ��ȯ", money.getId(), money.getName(), money.realValue()/money.getFaceValue() ));
	}

}
 