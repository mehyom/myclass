package edu.sswu.vm;

import java.util.Arrays;
import java.util.List;

import edu.sswu.vm.io.InputBill;
import edu.sswu.vm.io.InputCoin;
import edu.sswu.vm.io.ReturnBill;
import edu.sswu.vm.io.ReturnCoin;

public class MoneyManager extends TransactionManager {
	static final int UNLIMIT_COIN_COUNT = 9999999;
	static final int UNLIMIT_BILL_COUNT = 999;
	private final Cash balance;
	public MoneyManager() {
		balance = new Cash();
		// 무한이라 가정
		List<Coin> coinList = Arrays.asList( 
				new Coin(4, "100", 100, UNLIMIT_COIN_COUNT),
				new Coin(5, "500", 500, UNLIMIT_COIN_COUNT));
		coinList.forEach( money -> balance.credits(money));
		List<Bill> billList = Arrays.asList(
				new Bill(6, "1000원", 1000, "SN"),
				new Bill(7, "5000원", 5000, "SN"));

		for (int i=0; i<UNLIMIT_BILL_COUNT; i++ ) {
			billList.forEach(bill -> 
				balance.credits( new Bill(bill.getId(), bill.getName(), bill.getFaceValue(), CashFactory.getInstance().getSerialNumber()) ));
		}
	}
	public void displayMoneyInput() {
		InputBill.getInstance().displayInputMessage();
		InputCoin.getInstance().displayInputMessage();
				
		int id = Utils.scanNumber();
		Money money = CashFactory.getInstance().moneyById(id);
		if (money == null) {
			System.out.println("\n [Warning] 올바른 화폐를 넣어주세요");
		} else {
			if (money instanceof Coin) {
				InputCoin.getInstance().input(money);
			} else {
				InputBill.getInstance().input(money);
			}			
			super.inputMoney( money );
		}
	}
	public void salesCash(int salesAmount) {
		int change = super.getChange() - salesAmount;
		super.getCash().moveTo(balance);
		if (change > 0) {
			Cash changeCash = CashFactory.getInstance().cashFromAmount(change);
			changeCash.moveTo(super.getCash());
		}
	}
	public void releaseCash() {
		super.bills.values().stream().flatMap(List::stream).forEach(bill -> ReturnBill.getInstance().input(bill));
		super.coins.values().stream().forEach(bill -> ReturnCoin.getInstance().input(bill));
		super.releaseCash();
	}
}
