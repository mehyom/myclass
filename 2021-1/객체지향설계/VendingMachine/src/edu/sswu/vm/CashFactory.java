package edu.sswu.vm;

import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class CashFactory {
	private final Map<Integer, MoneyModel> moneyMap;
	private final List<MoneyModel> coinList;
	private final List<MoneyModel> billList;
	private final List<MoneyModel> moneyList;
	private static  CashFactory cashFactory;
	private Long serialNumber = 0L;
	public CashFactory() {
		coinList = Arrays.asList( 
				new MoneyModel(4, "100원", 100, true),
				new MoneyModel(5, "500원", 500, true)
				);
		billList = Arrays.asList(
				new MoneyModel(6, "1000원", 1000, false),
				new MoneyModel(7, "5000원", 5000, false)
				);
		 Collections.sort(billList, Comparator.comparing(MoneyModel::getFaceValue).reversed());
		 Collections.sort(coinList, Comparator.comparing(MoneyModel::getFaceValue).reversed());
		 moneyList = Stream.concat(billList.stream(), coinList.stream()).collect(Collectors.toList());
		 moneyMap = moneyList.stream()
				 .collect(Collectors.toMap( item -> item.getId(), item -> item));
	}
	public static CashFactory getInstance() {
		if (null == cashFactory) {
			cashFactory = new CashFactory();
		}
		return cashFactory;
	}
	public String getSerialNumber() {
		return "SN"+ (++serialNumber);
	}
	public Money moneyById(int id) {
		MoneyModel model = moneyMap.get(id);
		return model == null ? null : moneyByModel(model);
	}
	public Cash cashFromAmount(int amount) {
		Cash cash = new Cash();
	
		int debitMoney = amount;
		for (MoneyModel money : moneyList) {
			while(debitMoney >= money.getFaceValue()) {
				debitMoney -= money.getFaceValue();
				cash.credits(moneyByModel(money));
			}
		}
		return cash;
	}	
	private Money moneyByModel(MoneyModel money) {
		if (money.isCoin()) {
			return new Coin(money.getId(), money.getName(), money.getFaceValue(), 1);
		} else {
			return new Bill(money.getId(), money.getName(), money.getFaceValue(), getSerialNumber());
		}		
	}
	public List<MoneyModel> getCoinList() {
		return coinList;
	}
	public List<MoneyModel> getBillList() {
		return billList;
	}
}
