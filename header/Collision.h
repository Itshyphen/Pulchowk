
class Collision
{
private:
    sf::Sprite player;
    sf::Sprite object;
public:

    //Checking the seperate axis theorem of collision for the player and object
    bool satRectangleAndPoints(const sf::Vector2f rectangleSize, const std::array<sf::Vector2f, 4>& points)
        {
            bool allPointsLeftOfRectangle{ true };
            bool allPointsRightOfRectangle{ true };
            bool allPointsAboveRectangle{ true };
            bool allPointsBelowRectangle{ true };
            for (auto& point : points)
            {
                if (point.x >= 0.f)
                    allPointsLeftOfRectangle = false;
                if (point.x <= rectangleSize.x)
                    allPointsRightOfRectangle = false;
                if (point.y >= 0.f)
                    allPointsAboveRectangle = false;
                if (point.y <= rectangleSize.y)
                    allPointsBelowRectangle = false;
            }
            return !(allPointsLeftOfRectangle || allPointsRightOfRectangle || allPointsAboveRectangle || allPointsBelowRectangle);
        }


/* returns a boolean representing if the two objects' rectangular boundaries are colliding
 allows the collision level to be specified:
     0: AABB (axis-aligned boundaries boxes)
     1: tests if any corners are inside opposite rectangle
     2: SAT (separating axis theorem)
    -1: maximum level (default)*/
    bool areColliding(const sf::Sprite player, const sf::Sprite object, const int collisionLevel = -1)
    {
        // checking the axis-aligned bounding box:AABB
        const bool level0{player.getGlobalBounds().intersects(object.getGlobalBounds()) };
        if (!level0 || collisionLevel == 0)
            return level0;

        // any corners inside opposite rectangle

        //Get the combined transform of the player and object
        const sf::Transform transform1{player.getTransform() };
        const sf::Transform transform2{object.getTransform() };

        //Get the inverse transform of the player and object
        const sf::Transform inverseTransform1{player.getInverseTransform() };
        const sf::Transform inverseTransform2{object.getInverseTransform() };

        //Get the local co-ordinates of the rectangle of player and object
        const sf::FloatRect rect1Bounds{player.getLocalBounds() };
        const sf::FloatRect rect2Bounds{object.getLocalBounds() };

        //Get size of local bounded rectangle of entities
        const sf::Vector2f rect1Size{ rect1Bounds.width, rect1Bounds.height };
        const sf::Vector2f rect2Size{ rect2Bounds.width, rect2Bounds.height };

        //Get the image of the player rectangle
        const sf::Vector2f rect1TopLeft{ inverseTransform2.transformPoint(transform1.transformPoint({ 0.f, 0.f })) };
        const sf::Vector2f rect1TopRight{ inverseTransform2.transformPoint(transform1.transformPoint({ rect1Size.x, 0.f })) };
        const sf::Vector2f rect1BottomRight{ inverseTransform2.transformPoint(transform1.transformPoint(rect1Size)) };
        const sf::Vector2f rect1BottomLeft{ inverseTransform2.transformPoint(transform1.transformPoint({ 0.f, rect1Size.y })) };

        //Get the image of the object rectangle
        const sf::Vector2f rect2TopLeft{ inverseTransform1.transformPoint(transform2.transformPoint({ 0.f, 0.f })) };
        const sf::Vector2f rect2TopRight{ inverseTransform1.transformPoint(transform2.transformPoint({ rect2Size.x, 0.f })) };
        const sf::Vector2f rect2BottomRight{ inverseTransform1.transformPoint(transform2.transformPoint(rect2Size)) };
        const sf::Vector2f rect2BottomLeft{ inverseTransform1.transformPoint(transform2.transformPoint({ 0.f, rect2Size.y })) };

        //If any side of the one rectangle contains any side of the another rectangle, then its collision
        const bool level1{ (
                                   (rect1Bounds.contains(rect2TopLeft)) ||
                                   (rect1Bounds.contains(rect2TopRight)) ||
                                   (rect1Bounds.contains(rect2BottomLeft)) ||
                                   (rect1Bounds.contains(rect2BottomRight)) ||
                                   (rect2Bounds.contains(rect1TopLeft)) ||
                                   (rect2Bounds.contains(rect1TopRight)) ||
                                   (rect2Bounds.contains(rect1BottomLeft)) ||
                                   (rect2Bounds.contains(rect1BottomRight))) };
        if (level1 || collisionLevel == 1)
            return level1;

        // LEVEL 2 (SAT) i.e if you are able to draw a line to separate two polygons, then they do not collide.
        std::array<sf::Vector2f, 4> rect1Points
                {
                        rect1BottomLeft,
                        rect1BottomRight,
                        rect1TopRight,
                        rect1TopLeft,
                };
        if (!satRectangleAndPoints(rect2Size, rect1Points))
            return false;
        std::array<sf::Vector2f, 4> rect2Points
                {
                        rect2BottomLeft,
                        rect2BottomRight,
                        rect2TopRight,
                        rect2TopLeft,
                };
        return satRectangleAndPoints(rect1Size, rect2Points);
    }
};