package spring.YHJpa.domain;

import lombok.Getter;
import lombok.Setter;
import spring.YHJpa.domain.item.Item;

import javax.persistence.*;

@Entity
@Table(name = "order_item")
@Getter @Setter
public class OrderItem {

    @Id
    @GeneratedValue
    @Column(name = "order_item_id")
    private Long id;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "item_id")
    private Item item;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "order_id")
    private Order order;

    private int orderPrice;

    private int count;

    //==Business Logic==//
    public void cancel() {
        getItem().addStock(count);
    }

    //==Lookup Logic==//
    public int getTotalPrice() {
        return getOrderPrice() * getCount();
    }
}
