package edu.sswu.vm.io;

import java.util.List;

import edu.sswu.vm.CashFactory;
import edu.sswu.vm.Money;

public class InputBill extends ExchangeMoney<Money> {
	private final List<? extends Money> moneyList;
	public InputBill() {
		this.moneyList = CashFactory.getInstance().getBillList();
	}
	private static final InputBill instance = new InputBill();
	public static InputBill getInstance() {
		return instance;
	}
	@Override
	public void displayInputMessage() {
		System.out.println( "\n ## �������Ա��� ��� ������ �ݾ� \n" +super.notifyMessage(moneyList) );
	}

	@Override
	public void input(Money money) {
		System.out.println(String.format(">> �������Ա� [%d] %s�� �Է�", money.getId(), money.getName() ));
	}

}
 