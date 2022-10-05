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
		System.out.println( "\n ## 지폐투입구에 사용 가능한 금액 \n" +super.notifyMessage(moneyList) );
	}

	@Override
	public void input(Money money) {
		System.out.println(String.format(">> 지폐투입구 [%d] %s권 입력", money.getId(), money.getName() ));
	}

}
 