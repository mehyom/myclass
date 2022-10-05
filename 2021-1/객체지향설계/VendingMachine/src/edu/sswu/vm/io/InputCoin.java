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
		System.out.println( "\n ## 동전투입구에 사용 가능한 금액 \n " +super.notifyMessage(moneyList) );
	}
	@Override
	public void input(Money money) {
		System.out.println(String.format(">> 동전투입구 [%d] %s 동전 입력", money.getId(), money.getName() ));
	}

}
 