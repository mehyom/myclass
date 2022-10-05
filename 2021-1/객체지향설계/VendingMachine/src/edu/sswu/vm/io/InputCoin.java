package edu.sswu.vm.io;

import java.util.List;

import edu.sswu.vm.CashFactory;
import edu.sswu.vm.Money;

public class InputCoin extends ExchangeMoney<Money> {
	private final List<? extends Money> moneyList;
	public InputCoin() {
		this.moneyList = CashFactory.getInstance().getCoinList();
	}
	private static final InputCoin instance = new InputCoin();
	public static InputCoin getInstance() {
		return instance;
	}

	@Override
	public void displayInputMessage() {
		System.out.println( "\n ## �������Ա��� ��� ������ �ݾ� \n " +super.notifyMessage(moneyList) );
	}
	@Override
	public void input(Money money) {
		System.out.println(String.format(">> �������Ա� [%d] %s ���� �Է�", money.getId(), money.getName() ));
	}

}
 