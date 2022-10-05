package edu.sswu.vm;

import java.util.List;
import java.util.stream.Collectors;

public class VendingMachine {
	StockManager stockManager;
	MoneyManager moneyManager;
	
	public VendingMachine() {
		stockManager = new StockManager();
		moneyManager = new MoneyManager();
	}
	public void launchApplication() {
		List<Product> productList = stockManager.queryItems();
		int change = 0;
		while (true) {
			change = moneyManager.getChange();
			displayItem(productList, change);
			try {
				Product selectProduct = selectItem();
				if (selectProduct == null) {
					System.out.println("\n [Warning] 올바른 음료를 선택해주세요");
					continue;
				}  
				if (selectProduct.getQty() <=0) {
					System.out.println(String.format("\n [Warning] 선택하신 [%d]%s는 재고가 없습니다 다른 음료를 선택해주세요", selectProduct.getId(), selectProduct.getName()));
					continue;
				}  
				// money input
				do {
					displayMoneyInput(selectProduct, change);
					change = moneyManager.getChange();
				} while ( (change = moneyManager.getChange()) <  selectProduct.getPrice());
				// return item
				displayWatingMessage(selectProduct, change);
				stockManager.releaseStock(selectProduct);
				moneyManager.salesCash(selectProduct.getPrice());
			} catch (ReturnMoneyException e) {
				exit();
			}
		}
	}
	private void exit() {
		int change = moneyManager.getChange();
		if (0 < change ) {
			System.out.println( String.format("\n [Message] 잔돈 %d원이 반환 됩니다", change));
			System.out.println( String.format(" [Message] 홈화면으로 돌아갑니다\n"));
			moneyManager.releaseCash();
		}		
	}
	private void displayWatingMessage(Product selectProduct, int change) {
		System.out.println(String.format(" [Message] 선택하신 상품 %s이(가) 나옵니다", 
				selectProduct.getName() ));
	}
	private void displayMoneyInput(Product selectProduct, int change) {
		System.out.println("\n=====================================================================================");
		System.out.println("##############                  << WELCOME SODA VM >>                  ##############");
		System.out.println("=====================================================================================");
		System.out.println("\n		 --------------------------------------------------");
		System.out.println("		ㅣ                                                ㅣ");
		System.out.println(String.format("		ㅣ       [선택 상품: %3s]                      ㅣ", selectProduct.getName() ));
		System.out.println("		ㅣ                                                ㅣ");
		System.out.println(String.format("		ㅣ       [가격: %4d원]   [부족한 금액: %4d원]   ㅣ", selectProduct.getPrice(), selectProduct.getPrice() - change));
		System.out.println("		ㅣ                                                ㅣ");
		System.out.println("		 --------------------------------------------------");
		System.out.println("\n  상품 대금을 넣어주세요! 사용 가능한 금액권 중 넣으실 화폐의 번호를 입력해주세요");
		System.out.println("\n								## 잔돈 반환 [ X ] ##");
		System.out.println("\n=====================================================================================");
		System.out.println("							현재 잔액은 " + change + " 원입니다");
		System.out.println("=====================================================================================");
		moneyManager.displayMoneyInput();
	}
	private boolean displayItem(List<Product> productList, int change) {
		String msg = productList.stream().map(item->String.format(" **제품 번호**  [ %d ] 번        **제품명**  [ %3s ]       **가격**  [ %4d ] 원              ", item.getId(), item.getName(), item.getPrice())).collect(Collectors.joining("\n\n"));
		System.out.println("\n=====================================================================================");
		System.out.println("##############                  << WELCOME SODA VM >>                  ##############");
		System.out.println("=====================================================================================\n");
		System.out.println(msg);
		System.out.println("\n								## 잔돈 반환 [ X ] ##");
		System.out.println("\n=====================================================================================");
		System.out.println("							현재 잔액은 " + change + " 원입니다");
		System.out.println("=====================================================================================");
		return true;
	}
	private Product selectItem() {
		// display guide message
		// input
		System.out.println("\n [Message] 자판기를 이용해주셔서 감사합니다! 원하시는 음료의 제품번호를 선택하세요");
		int selectItem = Utils.scanNumber();
		Product product = stockManager.queryStock(selectItem);
		return product;
	}
}
