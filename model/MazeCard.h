#ifndef MAZECARD_H
#define MAZECARD_H

#include "MazeCardShape.h"
#include <stdexcept>

namespace labyrinth {

/**
 * @brief Represents a maze card. A maze card is card representing one of the
 * pathways of the maze.
 */
class MazeCard
{

protected:

    /**
     * @brief Is the shape of this maze card.
     */
    MazeCardShape shape_;

    /**
     * @brief Tells if this maze card is movable or not.
     */
    bool isMovable_;

public:

    /**
     * @brief Constructs this maze card.
     *
     * @param shape is the shape of this maze card.
     * @param isMovable is true if this maze card can be moved.
     */
    MazeCard(const MazeCardShape &shape, bool isMovable=true)
        : shape_{shape},
          isMovable_{isMovable}
    {}

    MazeCard() = default;

    MazeCard(const MazeCard &) = default;

    MazeCard(MazeCard &&) = default;

    /**
     * @brief Tells if this maze card is movable.
     *
     * @return true if this maze card is movable.
     */
    bool isMovable() const { return isMovable_; }

    /**
     * @brief getShape Gets the shape of the MazeCard.
     * @return the shape of the MazeCard.
     */
    MazeCardShape getShape(){return shape_;}

    /**
     * @brief Tells if this card is a T.
     *
     * @return true if this card is a T.
     */
    bool isT() const {return shape_.isT();}

    /**
     * @brief Tells if this card is a T.
     *
     * @return true if this card is a T.
     */
    bool isL() const {return shape_.isL();}

    /**
     * @brief Tells if this card is a T.
     *
     * @return true if this card is a T.
     */
    bool isI() const {return shape_.isI();}

    /**
     * @brief Tells if this maze card is going to the given position.
     *
     * @param direction is the direction this maze card is going to.
     * @return true if this maze card is going right.
     */
    bool isGoing(const MazeDirection direction) const {
        return shape_.isGoing(direction);
    }

    /**
     * @brief Rotates this maze card.
     */
    void rotate() {
        isMovable_ ? shape_.rotate() :
                     throw std::logic_error("The card couldn't be rotated"
                                            " because she isn't movable");
    }

    bool hasSameType(const MazeCard other){
        (other.isI() && this->isI()) || (other.isT() && this->isT())
                        || (other.isL() && this->isL());
    }
    bool isEqualTo(const MazeCard other){
        return hasSameType(other) && ((other.isMovable() && this->isMovable()) ||
                (!other.isMovable() && !this->isMovable()));
    }
    ~MazeCard() = default;

    MazeCard& operator=(const MazeCard &that)
    {
        shape_ = that.shape_;
        isMovable_ = that.isMovable_;
        return *this;
    }

    bool operator==(const MazeCard other){
        return isEqualTo(other);
    }

};

}

#endif // MAZECARD_H
